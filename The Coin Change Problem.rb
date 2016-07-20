n = gets.chomp.strip.split.map(&:to_i)[0]
arr = gets.chomp.strip.split.map(&:to_i)

table = Array.new(arr.length + 1) { Array.new(n + 1, 0) }

for i in 0..arr.length
  table[i][0] = 1
end

for j in 1..n
  table[0][j] = 0
end

for i in 1..arr.length
  for j in 1..n
    if arr[i - 1] <= j
      table[i][j] = table[i - 1][j] + table[i][j - arr[i - 1]]
    else
      table[i][j] = table[i - 1][j]
    end
  end
end

puts table[table.length - 1][n]
