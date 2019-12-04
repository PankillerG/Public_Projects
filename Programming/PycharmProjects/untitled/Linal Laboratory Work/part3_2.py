def my_pascal(dim):
P = np.zeros((dim, dim))
i,j = np.indices(P.shape)
P[i==0] = int(1)
P[j==0] = int(1)
for i in range(1, dim):
    for j in range(1, dim):
        P[i,j] = int(P[i-1,j]) + int(P[i,j-1])
return P