def calculate(arr)
  left, right = Array.new(arr.length, 1), Array.new(arr.length, 1)

  for i in 1...arr.length
    left[i] = 1 + left[i - 1] if arr[i] > arr[i - 1]
  end

  for i in (arr.length - 2).downto(0)
    right[i] = 1 + right[i + 1] if arr[i] > arr[i + 1]
  end
  left.zip(right).inject(0) { |sum, n| sum + n.max }
end

N, arr = gets.chomp.strip.to_i, []

for i in 0...N
  arr << gets.chomp.strip.to_i
end

puts calculate(arr)
