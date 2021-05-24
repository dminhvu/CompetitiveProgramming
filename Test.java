
import java.util.*;

/**
 * Program that determines whether word ladders exist between a specific pair of
 * words.
 * 
 * @author ??
 */
public class Test {
	private static boolean isLadder(String a, String b) {
		int countDifference = 0;

		for (int i = 0; i < a.length(); i++) {
			char currCharA = a.charAt(i);
			char currCharB = b.charAt(i);
			if (currCharA != currCharB) {
				countDifference++;
			}
		}

		return countDifference == 1;
	}

	private static boolean ladderExists(Set<String> words, Set<String> picked, String from, String to) {
		if (isLadder(from, to) && !picked.isEmpty()) {
			return true;
		}

		for (String eachWord : words) {
			if (isLadder(from, eachWord) && !picked.contains(eachWord)) {
				Set<String> temp_picked = picked;
				temp_picked.add(eachWord);
				if (ladderExists(words, temp_picked, eachWord, to)) return true;
			}
		}
		return false;
	}

	/**
	 * Returns whether a word ladder can be constructed using words between from and
	 * to.
	 * 
	 * @param words the dictionary of words to use.
	 * @param from  the starting word in the ladder.
	 * @param to    the ending word in the ladder.
	 * @return true iff a word ladder can be constructed from --> to.
	 */
	public static boolean ladderExists(Set<String> words, String from, String to) {
		Set<String> picked = new HashSet<String>();
		return ladderExists(words, picked, from, to); // placeholder to ensure compilation, remove when done!
	}

	/** Main tester method */
	public static void main(String[] args) {

		// Set<String> words1 = new TreeSet<String>();
		// words1.add("hot");
		// words1.add("dot");
		// words1.add("dog");

		// System.out.println(ladderExists(words1, "hit", "cog")); // true

		// Set<String> words2 = new TreeSet<String>();
		// words2.add("hot");
		// words2.add("dot");
		// words2.add("dog");
		// words2.add("lot");
		// words2.add("log");

		// System.out.println(ladderExists(words2, "hit", "cog")); // true

		Set<String> words3 = new TreeSet<String>();
		words3.add("rain");
		words3.add("ruin");
		words3.add("gain");
		words3.add("grin");
		words3.add("grit");
		words3.add("main");
		words3.add("pain");
		words3.add("pair");
		words3.add("pail");
		words3.add("mail");

		System.out.println(ladderExists(words3, "sail", "ruip")); // true

		// Set<String> words4 = new TreeSet<String>();
		// words4.add("mist");
		// words4.add("fist");
		// words4.add("fish");

		// System.out.println(ladderExists(words4, "lost", "cost")); // false

		// Set<String> words5 = new TreeSet<String>();
		// words5.add("mist");
		// words5.add("fist");
		// words5.add("fish");
		// words5.add("most");

		// System.out.println(ladderExists(words5, "lost", "cost")); // true
	}
}