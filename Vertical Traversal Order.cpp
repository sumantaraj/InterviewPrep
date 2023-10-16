/*
Problem :Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 Example 1:
Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
*/

class Solution {
    public:
        int findMinDifference(vector<string>& timePoints) {
    
            vector<int> minutes;
    
            for(int i=0;i<timePoints.size();i++)
            {
                string s=timePoints[i];
    
                int hours= stoi(s.substr(0,2));
                 int min= stoi(s.substr(3,2));
    
                 int total=hours*60+min;
    
                 minutes.push_back(total);
            }
            sort(minutes.begin(),minutes.end());
    
            int mini=INT_MAX;
            for(int i=0;i<minutes.size()-1;i++)
            {
                int diff=minutes[i+1]-minutes[i];
                mini=min(mini,diff);
            }
            int last=(minutes[0]+1440)-minutes[minutes.size()-1];
            mini=min(mini,last);
    
    
            return mini;
        }
    };

    /*Python solution 
    class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        # Use a dict to store our answers, keys will be column idxs.
        ans = collections.defaultdict(list)
        
        def helper(node, row, col):
            if not node:
                return
			# Append node vals to column in our dict.
            ans[col].append((row, node.val)) 
			# Traverse l and r.
            helper(node.left, row + 1, col - 1)
            helper(node.right, row + 1, col + 1)
            
        helper(root, 0, 0)
        # Sort our dict by keys (column vals)
        ans = dict(sorted(ans.items()))
        res = []
		# Loop through our sorted dict appending vals sorted by height (top down order).
        for k, v in ans.items():
            res.append([x[1] for x in sorted(v, key=lambda x:x)])
            
        return res
    
    */
