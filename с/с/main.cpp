//
//  main.cpp
//  с
//
//  Created by Kaysar on 07.04.16.
//  Copyright © 2016 Kaysar. All rights reserved.
//

#include <iostream>

using namespace std;

int root[100001], coun = 0;

int find_set(int vertex) {
    if(vertex == root[vertex])
        return vertex;
    return root[vertex] = find_set(root[vertex]);
}

void make_union(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        root[a] = b;
        coun--;
    }
    
}

int main() {
    // insert code here...
    int k, n, m, a[100001], b[100001], c[100001], touched[100001];
    
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++)
        cin >> a[i] >> b[i];
    
    for(int i = 1; i <= n; i++)
        root[i] = i;
    
    cin >> k;
    
    for(int i = 0; i < k; i++) {
        cin >> c[i];
        touched[c[i]] = 1;
    }
    coun = n;
    
    for(int i = 1; i <= m; i++) {
        if(!touched[i]) {
            make_union(a[i], b[i]);
        }
    }
    
    int answer[100001];
    int o = 0;
    while(k--) {
        answer[o] = coun;
        o++;
        make_union(a[c[k]], b[c[k]]);
    }
    sort (answer, answer + o);
    for (int i = 0; i  < o; i++)
        cout << answer[i] << " " ;
    
    
    return 0;
}
