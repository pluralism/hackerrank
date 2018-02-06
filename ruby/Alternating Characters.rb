t = gets.chomp.to_i
s = ""

for i in 0...t
  s = gets.chomp
  total = 0
  
  for j in 0..s.length - 1
    if s[j] == s[j + 1]
      total = total + 1
    end
  end
  puts total
end