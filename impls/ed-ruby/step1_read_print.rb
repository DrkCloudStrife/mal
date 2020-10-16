require_relative "reader"

def READ(input)
  input
end

def EVAL(input)
  input
end

def PRINT(input)
  input
end

def rep(input)
  PRINT(EVAL(READ(input)))
end

while true
  puts "user> "
  break unless input = gets
  puts rep(input)
end
