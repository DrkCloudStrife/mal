def pr_str(input)
  if input.is_a?(Array)
    resp = "("
    input.each do |t|
      resp += pr_str(t)
    end
    resp += ")"
    return resp
  else
    input.to_s
  end
end
