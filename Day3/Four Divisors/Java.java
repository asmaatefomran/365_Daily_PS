class Solution {
    public ArrayList<Integer> getDiv(int n){
        ArrayList<Integer> divs=new ArrayList<>();
        for(int i=1;1L*i*i<=n;++i){
            if(n%i==0){
                divs.add(i);
                if(n/i!=i)divs.add(n/i);
            }
        }
        return divs;
    }
    public int sumFourDivisors(int[] nums) {
        int sum=0;
        for(int i:nums){
            ArrayList<Integer> curr= getDiv(i);
            if(curr.size()==4){
                for(Integer j:curr)sum+=j;
            }
        }
        return sum;
    }
}
