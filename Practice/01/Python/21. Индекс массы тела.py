def bmi(weight: float, height: float) -> float:
    height = height / 100
    return weight / (height ** 2)

def print_bmi(bmi: float) -> float:
   if (bmi < 18.5):
       print("Underweight")
   elif (bmi < 25):
       print("Normal")
   elif (bmi < 30):
       print("Overweight")
   else:
       print("Obesity")
  
height, weight = map(float, input('Write you height and weight: ').split(' ')); 
print_bmi(bmi(weight, height))


