function [cipherText] = encrypt(plainText,key)
  cipherText = char(mod(double(plainText-97)+key,26)+97)
end
