# Betweenness Centrality of Global Airports

![](pic/output.PNG)__

## Leading Question 

Our problem is betweenness centrality mapping. Our goal is to derive the centrality of all the airports, and generates the heat map in the PNG format. From the graph, we can tell the centrality of the airport. Based on the output, We can make comment on the importance of airports in the world. 

## Dataset Acquisition

We will used the dataset from https://openflights.org/data.html. 

## Data Format

The original data format of this dataset is .dat. For each row, the col represents the information related to this airport, like airline ID, country, etc... The size of this dataset is ~400KB. Currently, we plan to only use the airline and airport information, which is the subset of the whole dataset.

## Data Correction

We will use Python to pre-processing the data which removes all the unused col, repetitive row, and rows without required information (airport or airline information). We will write some test cases that checks the value inside certain col is not NULL. Also, the numerical value is within some tolerance range.

## Data Storage

We will use graph to store our data. Since each node will have 2 data segments, the graph will take total of $O(n)$ storage. 

## Algorithm


##### Directed weighted Graph

We will be using this graph to store all the data. Each node inside the graph will be represented as an airport. The edge between the node will be represent as an airline. The reason for using the directed is that there might be some one-way only airlines. Because we want generate more realistic graph, so we have to use directed graph. The runtime of this algorithm is $O(n)$

##### Floyd–Warshall algorithm

After exploring a lot of shortest path algorithms on the website, we believe that the Floyd–Warshall algorithm is more efficient and relative easier for us to implement. We will use this algorithm to find shortest paths between 2 nodes, and then update the weight of the edge between these nodes. The runtime of this algorithm is $O(n^2)$

##### Betweenness Centrality

The equation we are going to used is: 
$$g(v)=\sum_{s\neq v\neq t}=\frac{\sigma_{st}(v)}{\sigma_{st}}$$

 The $\sigma_{st}(v)$ is the shortest paths that passing through the node v from $Node \: S$ and $Node \:T$.


##### Data Visualization

We will be using the PNG classes from the CS 225 MP to generate the picture output of our graph. The runtime of this algorithm is $O(n)$

## Run

simply execute the code below and waiting for executing. After the program end processing, it will generate a file `result.csv` in base fold which contain the betweenness centrality for all vertexes:

```bash
make calc_bc
```

after generating the `result.csv` file, you can visualize the bc value on map by running:

```bash
make
```

## Timeline (DDL date)

11/18 finished the data cleaning

11/18 complete 80% of the graph implmentation

11/20 completed BFS of the graph

11/21 complete the Floyd–Warshall algorithm

11/22 merge everything and start the update weight method

11/23 convert the graph to PNG output
