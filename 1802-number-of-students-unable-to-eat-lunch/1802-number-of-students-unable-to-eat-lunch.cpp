class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

      for (int student : students) {
          q.push(student);
       }

       int i=0;
       int rotate=0;
       while (!q.empty() && i < sandwiches.size()){

        if(q.front()==sandwiches[i]){
        q.pop();
        i++;
        rotate=0;
        }
        else{
             int student = q.front();
                q.pop();
                q.push(student);
                 rotate++;

                 if (rotate == q.size())
                 break;
        }

       }
       return q.size();
    }
};