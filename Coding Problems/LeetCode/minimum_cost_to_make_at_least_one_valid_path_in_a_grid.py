class Solution(object):
    def minCost(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        m = len(grid[0])
        dist = [[10**9 for j in range(m)] for i in range(n)]
        dist[0][0] = 0
        dir =[
            [0, 1, 1],
            [0,-1, 2],
            [1, 0, 3],
            [-1,0, 4]
        ]
        def bfs():
            head_index = tail_index = 0
            queue = []
            queue.append([0,0])
            while tail_index <= head_index:
                cur_x, cur_y = queue[tail_index]
                tail_index += 1
                for i in range(4):
                    nxt_x = cur_x + dir[i][0]
                    nxt_y = cur_y + dir[i][1]
                    dir_type = dir[i][2]
                    cost = (dir_type != grid[cur_x][cur_y])
                    if nxt_x < 0 or nxt_x >= n:
                        continue
                    if nxt_y < 0 or nxt_y >= m:
                        continue
                    if dist[nxt_x][nxt_y] > dist[cur_x][cur_y] + cost:
                        dist[nxt_x][nxt_y] = dist[cur_x][cur_y] + cost
                        queue.append([nxt_x,nxt_y])
                        head_index += 1
            return dist[n - 1][m - 1]
        return bfs()
