#Law of Large numbers

n <- 1000000
counter <- 0
for (i in rnorm(N)) {
    if (i > -1 & i < 1) {
        counter <- counter + 1
    }
}
answer <- counter / N
answer

#answer should be 68.2%