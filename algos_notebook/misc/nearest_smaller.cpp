/*
 NEAREST INTERGER SMALLER AND TO THE LEFT
 O(n)
*/

// Returns a vector near[n], where near[i] is an idx j such that v[j] < v[i]
// and j < i and j is the rigthmost possible index
vector<int> ns(vector<int> v) { 

    vector<int> near;
    stack< pair<int, int> > st; 
    for (int i = 0; i < v.size(); i++) { 
        while (!st.empty() && st.top().first >= v[i]) st.pop(); 

        if (st.empty()) near.push_back(-1); // all previews elements are bigger
        else near.push_back(st.top().second);

        st.push({v[i], i}); 
    } 

    return near;
} 