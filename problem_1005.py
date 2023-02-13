n = int(input().strip())
weights = [int(x) for x in input().strip().split()]

# Initialize maximum possible difference between the piles is minimal
result = 100000 * n

#  Binary number representation of a combination need n bits to show 2^n combinations

# 2^n contiguous numbers represent all combinations of n bits 
for combination in range(2**n):
    first_pile = 0
    second_pile = 0
    for bit_i in range(n):
        """
        Explain is_ith_bit_in_first_pile:
        Example: Check 3-th bit is 1 or 0
            - Right shift 3 bits: 010101 -> 000101
            - Bitwise AND operation with 1: 000101 AND 00001 -> 00001
            - Check result is 1: 00001 = 00001 -> True
        """
        is_ith_bit_1 = (combination >> bit_i) & 1 == 1
        if is_ith_bit_1:
            first_pile += weights[bit_i]
        else:
            second_pile += weights[bit_i]
    different = abs(first_pile - second_pile)
    result = min(result, different)
print(result)



# Class load dataset for machine translation model with datasets API in pytorch



def preprocess_function(examples):
    inputs = [prefix + example[source_lang] for example in examples["translation"]]
    targets = [example[target_lang] for example in examples["translation"]]
    model_inputs = tokenizer(inputs, text_target=targets, max_length=128, truncation=True)
    return model_inputs