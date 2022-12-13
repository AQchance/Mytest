package 第五次上机作业;
import java.util.*;
public class Test2 {
		public static void main(String[] args) {
			Scanner input = new Scanner(System.in);
			int t = input.nextInt();
			HashMap <HashSet<Integer>, Integer> theID = new HashMap<HashSet<Integer>, Integer>();
			ArrayList<HashSet<Integer>> theSet = new ArrayList<HashSet<Integer>>();
			
			for(int i = 0; i < t; i++) {
				int n = input.nextInt();
				Stack<Integer> s = new Stack<Integer>();
				for(int j = 0; j < n; j++) {
					String x = input.next();
					char temp = x.charAt(0);
					if(temp == 'P')
						s.push(ID(new HashSet<Integer>(), theID, theSet));
					else if(temp == 'D')
						s.push(s.peek());
					else {
						HashSet<Integer> x1 = new HashSet<Integer>(theSet.get(s.pop()));
						HashSet<Integer> x2 = new HashSet<Integer>(theSet.get(s.pop()));
						if(temp == 'U')
							x2.addAll(x1);
						else if(temp == 'I')
							x2.retainAll(x1);
						else
							x2.add(ID(x1, theID, theSet));
						s.push(ID(x2, theID, theSet));
					}
					System.out.println(theSet.get(s.peek()).size());
				}
				System.out.println("***");
			}
		}
		public static Integer ID(HashSet<Integer> x, HashMap<HashSet<Integer>, Integer> theID,
				ArrayList<HashSet<Integer>> theSet) {
			if(theID.containsKey(x))
				return theID.get(x);
			theSet.add(x);
			theID.put(x, theSet.size() - 1);
			return theSet.size() - 1;
		}
	}

