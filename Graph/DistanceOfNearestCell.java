import java.util.*;
import java.lang.*;

class Node{
	int i;
	int j;
	int d;

	public Node(int i, int j, int d){
		this.i = i;
		this.j = j;
		this.d = d;
	}
}

class DistanceOfNearestCell{

	public ArrayList<ArrayList<Integer>> distance(ArrayList<ArrayList<Integer>> A){
		int N = A.size();
		int M = A.get(0).size();

		
		int[][] ans = new int[N][M];
		// boolean[][] visited = new boolean[N][M];

		// for(ArrayList a: ans)
		// 	System.out.println(a);

		Queue<Node> q = new LinkedList<>();
		boolean[][] visited = new boolean[N][M];

		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				visited[i][j] = false;
				ans[i][j] = Integer.MAX_VALUE;
				if( A.get(i).get(j) == 1){
					q.add(new Node(i, j, 0));
					visited[i][j] = true;
					ans[i][j] = 0;
				}
			}
		}

		while(q.size() > 0){
			Node t = q.poll();

			int x = t.i;
			int y = t.j;
			int d = t.d;

			if( x + 1 < N && !visited[x+1][y] && (d + 1) < ans[x+1][y]){
				q.add(new Node(x+1, y, d+1));
				visited[x+1][y] = true;
				ans[x+1][y] = d+1;
			}
			if( x - 1 > -1 && !visited[x-1][y] && (d + 1) < ans[x-1][y]){
				q.add(new Node(x-1, y, d+1));
				visited[x-1][y] = true;
				ans[x-1][y] = d+1;
			}
			if( y + 1 < M && !visited[x][y+1] && (d + 1) < ans[x][y+1]){
				q.add(new Node(x, y+1, d+1));
				visited[x][y+1] = true;
				ans[x][y+1] = d+1;
			}
			if( y - 1 > -1 && !visited[x][y-1] && (d + 1) < ans[x][y-1]){
				q.add(new Node(x, y-1, d+1));
				visited[x][y-1] = true;
				ans[x][y-1] = d+1;
			}
		}

		ArrayList<ArrayList<Integer>> a = new ArrayList<>(N);
		for(int i = 0; i < N; i++){
			ArrayList<Integer> b = new ArrayList<>();
			for(int j = 0; j < M; j++){
                b.add(ans[i][j]);
            }
            a.add(b);
		}
		
		return a;
	}


	public static void main(String args[]){
		ArrayList<ArrayList<Integer>> A = new ArrayList<>();

		int N = 3;
		int M = 4;
		// ArrayList<Integer> b = new ArrayList<>();
		Scanner sc = new Scanner(System.in);

		for(int i = 0; i<N; i++){
			String s[] = sc.nextLine().split(" ");

			ArrayList<Integer> b = new ArrayList<>();
			for(int j = 0; j < M; j++){
				b.add(Integer.valueOf(s[j]));
			}
			A.add(b);
		}


		DistanceOfNearestCell obj = new DistanceOfNearestCell();
		ArrayList<ArrayList<Integer>> a = obj.distance(A);

		for(ArrayList<Integer> aa: a){
			for(Integer i: aa)
				System.out.print(i + " ");
			System.out.println();
		}

	}
}