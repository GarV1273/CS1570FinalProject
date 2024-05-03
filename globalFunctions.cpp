int getUniqueID() {
    static int id = 0;
    return ++id;
}