void someFunc() {
    int *p = new int;

    *p = 99;

    p = nullptr;
}

int main() {
    someFunc();

    return 0;
}
