template <typename T> class ListItem;
template <typename T> class List {
public:
    List<T>();
    List<T>(const List<T> &);
    List<T>& operator=(const List<T> &);
    ~List();
};