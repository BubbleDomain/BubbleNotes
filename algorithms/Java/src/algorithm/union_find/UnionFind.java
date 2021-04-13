package algorithm.dynamic_programming;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/3/16
 * @description: UnionFind
 */

class UnionFind {
	int count;
	private int[] parents;
	public UnionFind(int cnt) {
		count = cnt;
		parents = new int[cnt];
		for (int i = 0; i < cnt; i++) parents[i] = i;
	}

	public int find(int p) {
		while (p != parents[p]) {
			parents[p] = parents[parents[p]];
			p = parents[p];
		}
		return p;
	}

	public void union(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		count--;
		parents[a] = b;
	}
}