    static_assert(sizeof(X) == sizeof(int), "There is an int in X");
    static_assert(sizeof(A) == sizeof(int), "There is an int in A");
    static_assert(sizeof(B) == sizeof(A) + sizeof(X), "B is an A with an X");