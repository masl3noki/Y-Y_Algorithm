import heapq


def calculate_distances(graph, starting_vertex):
    distances = {vertex: float('inf') for vertex in graph}
    distances[starting_vertex] = 0

    pq = [(0, starting_vertex)]
    while len(pq) > 0:
        current_distance, current_vertex = heapq.heappop(pq)

        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))

    return distances


# input
N, K = map(int, input().split(" "))
graph = {}
for node in range(N):
    graph[str(node+1)] = {}

for _ in range(K):
    buff = list(map(int, input().split(" ")))
    main_key = str(buff[0])
    key = str(buff[1])
    value = buff[2]

    graph[main_key][key] = value

A, B = map(int, input().split(" "))

# main
print(graph)
answer = calculate_distances(graph, str(B))
print(answer)
print(answer[str(A)])
