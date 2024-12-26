import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] nums) {
        HashSet<Integer> pokemons = new HashSet<>();
        
        for(int i = 0; i < nums.length; i++){
            pokemons.add(nums[i]);
        }
        
        int n = nums.length / 2;
        
        return pokemons.size() > n ? n : pokemons.size();
    }
}