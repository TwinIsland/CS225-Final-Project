from pickle import load
from csv import writer


def flatten(l):
    return [item for sublist in l for item in sublist]


with open("edge.pkl", "rb") as f:
    routes_unique = load(f)

with open("vertex.pkl", "rb") as f:
    airport = load(f)


size_sm = int(input("generate dataset with edge: "))

routes_sm = routes_unique[:size_sm]

only_vertex = []

for i in routes_sm:
    only_vertex.append([i[0], i[1]])

vertex_sm = set(flatten(only_vertex))

with open("edge_sm.csv", "w", newline='') as f:
    csv_writer = writer(f)
    csv_writer.writerows(routes_sm)


with open("vertex_sm.csv", "w", newline='') as f:
    csv_writer = writer(f)
    for i in vertex_sm:
        csv_writer.writerow([i, airport[i][0], airport[i][1], airport[i][2]])

input("done")

