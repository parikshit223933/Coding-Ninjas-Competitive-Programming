void print(int n){
    if(n == 1){
        cout << 1 << " ";
        return;
    }
    print(n - 1);
    cout << n << " ";
    
}