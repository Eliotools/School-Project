#!/usr/bin/env python3

import sys
 
class Graph():
 
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)]
                      for row in range(vertices)]
 
    def printSolution(self, dist):
        global path
        path.append(dist)
    def minDistance(self, dist, sptSet):
 
        min = sys.maxsize
 
        for v in range(self.V):
            if dist[v] < min and sptSet[v] == False:
                min = dist[v]
                min_index = v
 
        return min_index
 
    def dijkstra(self, src):
 
        dist = [sys.maxsize] * self.V
        dist[src] = 0
        sptSet = [False] * self.V
 
        for cout in range(self.V):
 
            u = self.minDistance(dist, sptSet)
 
            sptSet[u] = True
 
            for v in range(self.V):
                if self.graph[u][v] > 0 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]:
                    dist[v] = dist[u] + self.graph[u][v]
 
        self.printSolution(dist)
 
 
g = Graph(13)
path = [] 
g.graph =   [[0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0],
            [1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0], 
            [0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0], 
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0], 
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0], 
            [0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0], 
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0], 
            [0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1], 
            [1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0], 
            [1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0], 
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0]] 

for loop in range(13):
    g.dijkstra(loop)
print(path)
 