class Test{
	
	public static String repeat(String s, int n) {
		if (n == 0) return "";
		String res = repeat(s, n / 2);
		if (n % 2 == 1) return res + res + s;
		return res + res;
	}
	public static void main(String[] args) {
		System.out.println(repeat("hel", 3));
	}
}