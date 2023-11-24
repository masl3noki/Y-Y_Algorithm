# Инициализация констант
infinity = float("inf")

class biGraph():
    def __init__(self, N, S, F, dist_matrix):
        self.__dist_matrix = dist_matrix
        self.__nodes_num = N
        self.__nodes_bgn = S
        self.__nodes_end = F

        self.__define_graph()

    def __define_graph(self):
        # Инициализация структуры
        self.graph = {}
        self.costs = {}
        self.parents = {}
        self.processed = []

        # Наполнение графов
        for node in range(self.__nodes_num):
            key = str(node + 1)

            # Наполнение главного графа
            self.graph[key] = {}
            for node_neighbour in range(self.__nodes_num):
                cost = self.__dist_matrix[node][node_neighbour]
                if cost > 0:
                    self.graph[key][str(node_neighbour + 1)] = cost

            # Наполнение графа стоимости
            if key != str(self.__nodes_bgn):
                self.costs[key] = infinity
            else:
                self.costs[str(self.__nodes_bgn)] = 0

            # Наполнение графа предков
            pass

    def __find_lowest_cost_node(self):
        # Если не нашли, то отдаем самый ужасный Null узел
        lowest_cost = infinity
        lowest_cost_node = None
        # Проход по хеш-таблице стоимости
        for node in self.costs:
            cost = self.costs[node]
            # Если это узел с наименьшей стоимостью из уже виденных в цикле,
            # и он еще не обработан...
            if cost < lowest_cost and node not in self.processed:
                # Он назначается новым усзлоом с min стоимостью
                lowest_cost = cost
                lowest_cost_node = node

        return lowest_cost_node

    def __dijkstra_algo(self):
        # Попробовать реализовать через do while?
        # Находим узел с min стоимостью среди необработанных
        node = self.__find_lowest_cost_node()
        # Проходим по соседям узла, пока все узлы не буду обработаны
        while node is not None:
            # Получаем стоимость и соседей рассматриваемой ноды
            cost = self.costs[node]
            neighbors = self.graph[node]
            # Перебор всех соседей рассматриваемого узла
            for n in neighbors.keys():
                # Стоимость узла определяется стоимостью пути до узла + ребром к узлу
                new_cost = cost + neighbors[n]
                # Если к соседу моэно быстрее добраться через текущий узел...
                if self.costs[n] > new_cost:
                    # ...обновить стоимость для этого узла
                    self.costs[n] = new_cost
            # Рассматриваемый узел помечается как обработанный
            self.processed.append(node)
            # Найти следующий узел для обработки и повторить цикл
            node = self.__find_lowest_cost_node()

    def getShortestPath(self):
        self.__dijkstra_algo()
        # Берем стоимость финишного узла
        answer = self.costs[str(self.__nodes_end)]
        # Если стоимость равна бесконечности (не дошли до узла), возвращаем по условию -1
        if answer == infinity:
            return -1
        return answer

    def getGraph(self):
        return self.graph

    def getCosts(self):
        return self.costs

    def getParents(self):
        return self.parents

# input
inpt = input().split(" ")
N, S, F = map(int, inpt[:3])
dist_matrix = []
for _ in range(N):
    buff = [int(x) for x in input().split()]
    dist_matrix.append(buff)

# main
Solution = biGraph(N, S, F, dist_matrix)

print(Solution.getShortestPath())