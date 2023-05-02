#include "Map.h"
int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    printf("\n");
    m.Set(10, "C");
    const char *x, *y;
    m.Get(30, x);
    m.Get(10, y);
    printf("%s %s %d\n", y, x, m.Count());
    m.Delete(20);
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    Map<int, const char*> m2;
    m2[10] = "a";
    m2[20] = "b";
    Map<int, const char*> m3;
    m3[10] = "c";
    printf("%d %d\n", m.Includes(m2), m.Includes(m3));
    m.Clear();
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}