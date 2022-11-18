import json


class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


with open("edge.json", "r", encoding="utf-8") as f:
    edge = list(json.load(f))

edge_unique = set()
edge_flat = []

for i in edge:
    edge_unique.add(i[0] + i[1])

print("TEST UNIQUENESS OF EDGE --- ", end='')
if len(edge) == len(edge_unique):
    print(bcolors.OKGREEN + "test pass!" + bcolors.ENDC)
else:
    print(bcolors.FAIL + "test fail: " + str(len(edge)) + "!=", str(len(edge_unique)) + bcolors.ENDC)
