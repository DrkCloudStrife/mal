RX = /[\s,]*(~@|[\[\]{}()'`~^@]|"(?:\\.|[^\\"])*"?|;.*|[^\s\[\]{}('"`,;)]*)/

class Reader

  def initialize(tokens)
    @tokens = tokens
    @position = 0
  end

  def next
    token = peek
    @position += 1
    token
  end

  def peek
    @tokens[@position]
  end

end

def read_str(input)
  tokens = tokenize(input)
  reader = Reader.new(tokens)

  read_form(reader)
end

def tokenize(input)
  input.scan(RX).flatten.reject{|t| t.empty? }
end

def read_form(reader)
  case reader.peek
  when "("
    reader.next
    read_list(reader)
  else
    read_atom(reader)
  end
end

def read_list(reader)
  token_col = []
  while reader.peek != ")"
    token_col << read_form(reader)
  end

  token_col
end

def read_atom(reader)
  reader.next
end
