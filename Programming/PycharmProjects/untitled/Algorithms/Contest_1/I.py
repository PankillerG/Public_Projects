def squad(one, two):
    return max(h * one, w * two)


def searchSquad(w, h, n):
    if n > 0:
        hh = 1
        ww = n
        while squad(hh, ww) > squad(hh + 1, (n + hh) // (hh + 1)):
            hh += 1
            ww = (n + hh) // (hh + 1)
        else:
            return squad(hh, ww)
    else:
        return max(w, h)


w, h, n = map(int, input().split())
print(searchSquad(w, h, n))
