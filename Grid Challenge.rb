t = gets.chomp.strip.to_i

for i in 0...t
  n, arr = gets.chomp.strip.to_i, []

  for i in 0...n
    arr << gets.chomp.strip.split("")
  end

  arr.map! { |n| n.sort }

  valid = true
  for i in 1...n
    break if !valid
    for j in 0...n
      break if !valid
      valid = false if arr[i][j] < arr[i - 1][j]
    end
  end
  if valid
    puts "YES"
  else
    puts "NO"
  end
end
