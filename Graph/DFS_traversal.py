def dfs(S, D, visited, ad_map):
    if S == D: return True

    visited[S] = True

    if S in ad_map:
        for s in ad_map[S]:
            if not visited[s]:
                return dfs(s, D, visited, ad_map)
    return False

def find_path(A, B):
    S = 1
    D = A

    ad_map = {}
    visited = [False]*(A+1)
    for i, j in B:
        if i not in ad_map:
            ad_map[i] = []
        ad_map[i].append(j)
    return dfs(S, D, visited, ad_map)


def main():
    A = 4
    # B = [
    #     [1,2],
    #     [4,1],
    #     [2,4],
    #     [3,4],
    #     [5,2],
    #     [1,3],
    # ]

    B = [
        [1,2],
        [2,3],
        [4,3],
    ]
    print(find_path(A, B))
if __name__ == "__main__":
    main()