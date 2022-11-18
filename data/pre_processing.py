# -*- coding: UTF-8 -*-


import geopy.distance
import csv
import json


def calc_dist(start_coord: tuple, dest_coord: tuple) -> float:
    """

    :param start_coord: (start latitude, start longitude)
    :param dest_coord:  (dest latitude, dest longitude)
    :return: linear distance between start and destination, in km
    """
    return geopy.distance.geodesic(start_coord, dest_coord).km


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
print("miss rate: ", str(fail_count / len(airport))[:4])

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

with open("edge.json", "w") as f:
    json.dump(routes_unique, f)

with open("vertex.json", "w") as f:
    json.dump(airport, f)
