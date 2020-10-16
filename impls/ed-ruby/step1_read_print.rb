require_relative "reader"
require_relative "printer"

def READ(input)
  read_str(input)
end

def EVAL(input)
  input
end

def PRINT(input)
  pr_str(input)
end

def rep(input)
  PRINT(EVAL(READ(input)))
end

while true
  puts "user> "
  break unless input = gets
  puts rep(input)
end
