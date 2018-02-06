string = gets.strip.downcase
chars = {}
isEvenLen = string.length.even?
found_odd = false
pal = true

string.each_char do |c|
  chars[c] == nil ? chars[c] = 1 : chars[c] += 1
end

chars.each_value do |value|
  if value.odd?
    if isEvenLen or found_odd
      pal = false
      break
    end
    found_odd = true
  end
end
puts pal ? "YES" : "NO"
