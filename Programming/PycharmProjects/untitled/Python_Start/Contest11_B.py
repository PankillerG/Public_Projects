print(
    len(
        set(
            open('input.txt', 'r').read().replace('\n', ' ').split()
        )
    )
)
