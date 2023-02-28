#include <stdio.h>
// Function prototypes
void bmiCalculation();
void bloodPressureAssessment();
void cardiacRiskScoreAssessment();
// Main function
int main() {
    int choice;
     // Display menu options and prompt user for choice
    printf("Please choose an option:\n");
    printf("1. BMI calculation\n");
    printf("2. Blood pressure assessment\n");
    printf("3. Cardiac risk score assessment\n");
    scanf("%d", &choice);

     // Call function based on user choice
    switch(choice) {
        case 1:
            bmiCalculation();
            break;
        case 2:
            bloodPressureAssessment();
            break;
        case 3:
            cardiacRiskScoreAssessment();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

// Function to calculate BMI
void bmiCalculation() {
    float weight, height, bmi;

    // Prompt user for weight and height
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);

    printf("Please enter your height in meters: ");
    scanf("%f", &height);
    // Calculate BMI
    bmi = weight / (height * height);

    // Interpret BMI result
    printf("Your BMI is %.2f.\n", bmi);
    if(bmi < 18.5) {
        printf("Underweight\n");
    } else if(bmi >= 18.5 & bmi <25) {
        printf("Normal\n");
    } else if(bmi >= 25 & bmi <30) {
        printf("Overweight\n");
    } else if(bmi >=30) {
        printf("obese\n");
    } else {
        printf("Invalid input.\n");
    }
}

// Function to blood pressure
void bloodPressureAssessment() {
    int systolic, diastolic;

    // Prompt user for systolic and diastolic blood pressure
    printf("Please enter your systolic blood pressure: ");
    scanf("%d", &systolic);

    printf("Please enter your diastolic blood pressure: ");
    scanf("%d", &diastolic);

    // Interpret blood pressure readings
    if(systolic < 120 && diastolic < 80) {
        printf("Your blood pressure is normal.\n");
    } else if(systolic >= 120 && systolic <= 129 && diastolic < 80) {
        printf("Your blood pressure is elevated.\n");
    } else if(systolic >= 130 && systolic <= 139 || diastolic >= 80 && diastolic <= 89) {
        printf("Your blood pressure is stage 1 hypertension.\n");
    } else if(systolic >= 140 || diastolic >= 90) {
        printf("Your blood pressure is stage 2 hypertension.\n");
    } else {
        printf("Invalid input.\n");
    }
}

// Function to cardiac risk score
void cardiacRiskScoreAssessment() {
    int age, gender, smoking, diabetes, systolic;
    float cholesterol, riskScore, cholesterol_float;


    // Prompt user for various risk factors
     printf("Please enter your age: ");
        scanf("%d", &age);

        printf("Please enter your gender (0 for female, 1 for male): ");
        scanf("%d", &gender);

        printf("Are you a smoker? (0 for no, 1 for yes): ");
        scanf("%d", &smoking);

        printf("Enter your total cholesterol (in mmol/L, between 1 and 9): ");
        scanf("%f", &cholesterol);
        while(cholesterol < 1.0 || cholesterol > 9.0) {
            printf("Your cholesterol value is out of range. Please enter a value between 1 and 9.\n");
            printf("Enter your total cholesterol (in mmol/L, between 1 and 9): ");
            scanf("%f", &cholesterol);
        }

        printf("Please enter your systolic blood pressure: ");
        scanf("%d", &systolic);

        printf("Do you have diabetes? (0 for no, 1 for yes): ");
        scanf("%d", &diabetes);


    // Calculate cardiac risk score based on inputs
    //The cardiac risk score used in the code is based on the Framingham Risk Score, which is a widely-used tool for assessing cardiovascular risk in individuals.
    riskScore = (0.0126 * age) + (0.1917 * gender) + (0.8511 * smoking) + (0.2857 * cholesterol) + (0.0202 * systolic) + (0.4164 * diabetes) - 12.0966;
    // https://www.mdcalc.com/calc/38/framingham-risk-score-hard-coronary-heart-disease#use-cases
    printf("Your Risk Score is %f\n",riskScore);
    // Determine level of risk based on calculated score
    if(riskScore < 5.0) {
        printf("Your cardiac risk is very low.\n");
    } else if(riskScore <= 5 & riskScore <9) {
        printf("Your cardiac risk is low.\n");
    } else if(riskScore <=10 & riskScore < 14) {
        printf("Your cardiac risk is moderate.\n");
    } else if(riskScore <=15 & riskScore <19) {
        printf("Your cardiac risk is moderate high.\n");
    } else if(riskScore <=20 & riskScore <29) {
        printf("Your cardiac risk is high.\n");
    } else {
        printf("Your cardiac risk is very high.\n");
    }
}

