//You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.
//The rules of a Unix-style file system are as follows:
//A single period '.' represents the current directory.
//A double period '..' represents the previous/parent directory.
//Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
//Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
//The simplified canonical path should follow these rules:

//The path must start with a single slash '/'.
//Directories within the path must be separated by exactly one slash '/'.
//The path must not end with a slash '/', unless it is the root directory.
//The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.



class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp;

        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                if(temp == ".."){
                    if(!st.empty()) st.pop();
                    temp.clear();
                }
                else if(temp.empty()){
                    temp.clear();
                }
                else if(temp == "."){
                    temp.clear();
                }
                else{
                    temp.push_back('/');
                    st.push(temp);
                    temp.clear();
                }
            }
            else{
                temp.push_back(path[i]);
            }
        }

        if(temp == "."){
            temp.clear();
        }

        if(temp == ".."){
            if(!st.empty()) st.pop();
            temp.clear();
        }

        temp.push_back('/');
        st.push(temp);

        vector<string> values;
        string ans = "";

        while(!st.empty()){
            values.push_back(st.top());
            st.pop();
        }

        reverse(values.begin(), values.end());

        for(auto p : values){
            ans += p;
        }

        while(!ans.empty() && ans.back() == '/'){
            ans.pop_back();
        }

        ans = "/" + ans;
        return ans;
    }
};
