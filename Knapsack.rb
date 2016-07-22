t = gets.chomp.strip.to_i

for i in 0...t
  expected_sum = gets.chomp.strip.split.map(&:to_i)[1]
  arr = gets.chomp.strip.split.map(&:to_i).uniq.sort

  table = Array.new(arr.length) { Array.new(expected_sum + 1, 0) }

  for j in arr[0]..expected_sum
    table[0][j] = [table[0][j], arr[0] + table[0][j - arr[0]]].max
  end

  for i in 1...arr.length
    for j in 1..expected_sum
      if j < arr[i]
        table[i][j] = table[i - 1][j]
      else
        table[i][j] = [table[i - 1][j], arr[i] + table[i][j - arr[i]]].max
      end
    end
  end
  puts table[arr.length - 1][expected_sum]
end
