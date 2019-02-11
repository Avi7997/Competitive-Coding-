
class Solution {
    Node root = new Node();

    public int findMaximumXOR(int[] nums) {
        if(nums == null || nums.length == 0) {
            return -1;
        }

        for(int n: nums) {
            insert(get32BitString(Integer.toBinaryString(n)), n);
        }


        return maximumXOR();
    }

    private String get32BitString(String bin) {
        int len = 32 - bin.length();
        StringBuilder sb = new StringBuilder(bin);
        while(len > 0) {
            sb.insert(0, '0');
            len--;
        }

        return sb.toString();
    }

    private void insert(String binary, int val) {
        Node node = root;
        for(int i = 0; i < binary.length(); i++) {
            char c = binary.charAt(i);
            if(!node.children.containsKey(c)) {
                node.children.put(c, new Node());
            }
            node = node.children.get(c);
        }
        node.isEnd = true;
        node.value = val;
    }

    private int maximumXOR() {
        Node num1 = root;
        Node num2 = root;
        while(!num1.isEnd && !num2.isEnd) {

            if(num1.children.containsKey('1') && num2.children.containsKey('0')) {
                num1 = num1.children.get('1');
                num2 = num2.children.get('0');
                continue;
            }
            if(num1.children.containsKey('0') && num2.children.containsKey('1')) {
                num1 = num1.children.get('0');
                num2 = num2.children.get('1');
                continue;
            }

            if(num1.children.containsKey('1')) {
                num1 = num1.children.get('1');
            } else if(num1.children.containsKey('0')) {
                num1 = num1.children.get('0');
            } else {
                break;
            }

            if(num2.children.containsKey('0')) {
                num2 = num2.children.get('0');
            } else if(num2.children.containsKey('1')) {
                num2 = num2.children.get('1');
            } else {
                break;
            }
        }
        System.out.println(num1.value + " " + num2.value);

        if(num1.isEnd && num2.isEnd && num1.value != -1 && num2.value != -1) {
            return num1.value ^ num2.value;
        }

        return -1;
    }
}

class Node {
    public HashMap<Character, Node> children;
    public boolean isEnd;
    public int value;

    public Node() {
        children = new HashMap<>();
        isEnd = false;
        value = -1;
    }
}
