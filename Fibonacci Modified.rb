input = gets.chomp.strip.split.map(&:to_i)
t1, t2, n = input[0], input[1], input[2]
dp = [t1, t2]

for i in 2...n
  dp[i] = dp[i - 2] + dp[i - 1] ** 2
end

puts dp[n - 1]
