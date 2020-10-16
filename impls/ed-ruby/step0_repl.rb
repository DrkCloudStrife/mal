def READ(input)
  return input
end

def EVAL(input)
  return input
end

def PRINT(input)
  return input
end

def rep(input)
  return PRINT(EVAL(READ(input)))
end

while true
  puts "user> "
  input = gets
  break if input.nil?
  puts rep(input)
end
