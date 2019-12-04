print(
    *map(
        lambda x: x.count(1) % 2,
        zip(
            *map(lambda y: map(
                lambda k: int(k), input().split()), range(int(input()))
                 )
        )
    )
)
