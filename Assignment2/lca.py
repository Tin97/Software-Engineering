class Graph(object):

    def __init__(self, graph_dict=None):
        if graph_dict == None:
            graph_dict = {}
        self.__graph_dict = graph_dict

    def vertices(self):
        return list(self.__graph_dict.keys())

    def edges(self):
        return self.__generate_edges()

    def add_vertex(self, vertex):
        if vertex not in self.__graph_dict:
            self.__graph_dict[vertex] = []

    def add_edge(self, edge):
        edge = set(edge)
        (vertex1, vertex2) = tuple(edge)
        if vertex1 in self.__graph_dict:
            self.__graph_dict[vertex1].append(vertex2)
        else:
            self.__graph_dict[vertex1] = [vertex2]

    def __generate_edges(self):
        edges = []
        for vertex in self.__graph_dict:
            for neighbour in self.__graph_dict[vertex]:
                if {neighbour, vertex} not in edges:
                    edges.append({vertex, neighbour})
        return edges

    def __str__(self):
        res = "vertices: "
        for k in self.__graph_dict:
            res += str(k) + " "
        res += "\nedges: "
        for edge in self.__generate_edges():
            res += str(edge) + " "
        return res

    def bfs(self, vertex):
        visited, queue = [], [vertex]
        while queue:
            vertex1 = queue.pop(0)
            for w in self.__graph_dict[vertex1]:
                if w not in visited:
                    visited.append(w)
                    queue.append(w)
        return visited

    def lca(self, vertex):
        return self.bfs(vertex).pop()


if __name__ == "__main__":

    g = { 1 : [4],
          2 : [3],
          3 : [2, 3, 4, 5],
          4 : [1, 3],
          5 : [3],
        }


    graph = Graph(g)

    print(graph.lca(1))
