# -*- coding: UTF-8 -*-


import geopy.distance
import csv
import pickle
import numpy as np
from collections import Counter


def calc_dist(start_coord: tuple, dest_coord: tuple) -> float:
    """

    :param start_coord:         (start latitude, start longitude)
    :param dest_coord:          (dest latitude, dest longitude)
    :return:                    linear distance between start and destination, in km
    """
    return geopy.distance.geodesic(start_coord, dest_coord).km


def calc_weight(distance: float, distance_max: float, airline: int) -> float:
    """

    :param distance:        distance of the edge
    :param airline:         number of airline
    :param distance_max:    maximum distance
    :return:                weight of the edge range from [0, 1]
    """

    """
    General Statistic Data
    -------------------------------------------
    std of distance info:    2020.1571858791772
    mean of distance info:   1851.8100171736605
    median of distance info: 1195.8845359502072
    max of distance info:    13804.402294725593
    
    std of airline:          1.2853277067594049
    mean of airline:         1.8069758652340586
    median of airline:       1.0
    max of airline:          20.0
    """

    # weight for each parameter
    distance_weight = 0.5
    airline_weight = 1 - distance_weight

    # get the fixed weight
    dest_fixed = distance / distance_max                        # TODO: use logarithm formula to get fixed dest
    airline_fixed = 1 / airline

    return airline_fixed * airline_weight + dest_fixed * distance_weight


airport = {}  # key: IATA code value: [latitude, longitude, altitude]
routes = []  # [start id, dist id, distance]

with open("airports.dat.txt", "r", newline='', encoding="utf-8") as f:
    csv_content = csv.reader(f, delimiter=',')
    for row in csv_content:
        airport[row[4]] = (float(row[6]), float(row[7]), float(row[8]))

print("fetch: ", len(airport.keys()), "airports")

with open("routes.dat.txt", "r", encoding="utf-8") as f:
    csv_content = csv.reader(f, delimiter=',')
    fail_count = 0
    for row in csv_content:
        start_airport = row[2]
        dest_airport = row[4]
        try:
            start_airport_dist = airport[start_airport]
            dest_airport_dist = airport[dest_airport]
        except KeyError:
            fail_count += 1
            continue
        dist = calc_dist(start_airport_dist[:2], dest_airport_dist[:2])
        routes.append([start_airport, dest_airport, dist])

print("fail: ", fail_count)
print("miss rate: ", str(fail_count / len(routes)))

# calculate weight and update routes
routes_ = np.array(routes, dtype=str)
route_flat = []

for i in routes_:
    route_flat.append(i[0] + i[1])

c = Counter(route_flat)

dist_inf = routes_[:, 2].astype(float)
dist_max = float(np.max(dist_inf))

for i in range(len(routes)):
    flat_name = routes[i][0] + routes[i][1]
    weight = calc_weight(float(routes[i][2]), dist_max, c[flat_name])
    routes[i][2] = weight

# remove duplicate edge
print("remove duplicate edge")
routes_unique = []
routes_visit = []
for i in routes:
    flat = i[0] + i[1]
    if flat in routes_visit:
        continue
    else:
        routes_visit.append(flat)
        routes_unique.append(i)

with open("edge.csv", "w", newline='') as f:
    csv_writer = csv.writer(f)
    csv_writer.writerows(routes_unique)

with open("vertex.csv", "w", newline='') as f:
    csv_writer = csv.writer(f)
    for i in airport.keys():
        csv_writer.writerow([i, airport[i][0], airport[i][1], airport[i][2]])

with open("edge.pkl", "wb") as f:
    pickle.dump(routes_unique, f)

with open("vertex.pkl", "wb") as f:
    pickle.dump(airport, f)

print("unique edge number: ", len(routes_unique))
print("done")
