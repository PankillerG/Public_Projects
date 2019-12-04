print(
    *list(
        map(
            lambda x, y: (x + y) % 2, list(map(int, input().split()))
        )
    )
)

