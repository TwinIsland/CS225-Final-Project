# Result

**Visualization:**

![](doc/sample.png)

**Floyd Warshall:**

It contains the shortest path information (include path and distance) between each vertexes. below shows small part of the output. For those row with weight equal to -1, it means that there is no such path between two airport.

```
Shortest path from: SUG to PEN is: SUG -> MNL -> SIN -> PEN with weight: 0.843141
Shortest path from: SUG to IQT is: SUG ->  with weight: -1
Shortest path from: SUG to MHQ is: SUG ->  with weight: -1
Shortest path from: SUG to LYC is: SUG ->  with weight: -1
Shortest path from: SUG to HTA is: SUG ->  with weight: -1
Shortest path from: SUG to DRW is: SUG -> MNL -> SIN -> DRW with weight: 1.18898
Shortest path from: SUG to TUG is: SUG -> MNL -> TUG with weight: 0.53564
Shortest path from: SUG to PNH is: SUG -> MNL -> SIN -> PNH with weight: 0.943769
```

**Betweenness Centrality:**

the whole dataset contains 6073 rows, the complete version can be find in [bc_whole_data.csv]([bc_whole_data.csv). below shows the top 20 biggest betweenness centrality of the data

| Airport IATA | Betweenness Centrality |
| ------------ | ---------------------- |
| LHR          | 1207419                |
| LAX          | 1086996                |
| ATL          | 1074177                |
| ORD          | 829192                 |
| PEK          | 729407                 |
| GRU          | 714964                 |
| ANC          | 682675                 |
| CDG          | 671505                 |
| SEA          | 616385                 |
| SIN          | 614232                 |
| MIA          | 564189                 |
| HKG          | 536958                 |
| BNE          | 536833                 |
| JFK          | 506446                 |
| DXB          | 493916                 |
| FRA          | 482255                 |
| YYZ          | 480450                 |
| DME          | 443768                 |
| BKK          | 399666                 |
| JNB          | 390034                 |

## Correctness

We use test case to check the correctness of out algorithm

## Conclusion

Our result shows that the most centralized airport are the most famous airport worldwide and also set at the critical point of the world. From our output,  `LHR`, `LAX`, `ATL`, which stand for Heathrow Airport, Los Angeles International Airport, Hartsfield-Jackson Atlanta International Airport, are the top3 airport with the biggest centrality. 

