#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Structure to store symptom-condition mapping
typedef struct {
    char symptom[100];
    char condition[100];
    char advice[256];
} SymptomData;

// Function prototypes
void displayMenu();
void handleSymptomsInput(SymptomData symptoms[], int count);
void provideFirstAidAdvice();
void provideSafetyGuidelines();
void detailedFirstAidOptions();
void detailedSafetyOptions();
void saveAdviceToFile(const char *advice);
void initializeSymptoms(SymptomData symptoms[], int *count);
void loadSymptomsFromFile(SymptomData symptoms[], int *count, const char *filename);
char *getCurrentTimestamp();
void showMentalHealthTips();
void recommendBasedOnFeeling();

// Main function
int main() {
    int choice;
    SymptomData symptoms[100]; // Array to store symptom data
    int symptomCount = 0;

    // Initialize symptoms in the program
    loadSymptomsFromFile(symptoms, &symptomCount, "symptoms.txt");

    while (1) {
        displayMenu();

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                handleSymptomsInput(symptoms, symptomCount);
                break;
            case 2:
                provideFirstAidAdvice();
                break;
            case 3:
                provideEmotionalSupportAdvice();
                break;
            case 4:
                provideSafetyGuidelines();
                break;
            case 5:
                printf("Exiting the program. Stay safe!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n--- MedAlert Emergency Assistance ---\n");
    printf("1. Input Symptoms\n");
    printf("2. First Aid Advice\n");
    printf("3. Mental Health Awareness\n");
    printf("4. Safety Guidelines\n");
    printf("5. Exit\n");
}

// Function to initialize symptoms from a file
void loadSymptomsFromFile(SymptomData symptoms[], int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error loading symptoms file");
        printf("Using default symptoms.\n");
        initializeSymptoms(symptoms, count);
        return;
    }

    while (fscanf(file, "%99[^,],%99[^,],%255[^\"]%*c", symptoms[*count].symptom, symptoms[*count].condition, symptoms[*count].advice) == 3) {
        (*count)++;
    }


    fclose(file);
}

// Function to initialize symptoms from a file or default data
void initializeSymptoms(SymptomData symptoms[], int *count) {
    strcpy(symptoms[*count].symptom, "fever");
    strcpy(symptoms[*count].condition, "Fever");
    strcpy(symptoms[*count].advice, "Stay hydrated and rest. Seek medical attention if fever persists for more than three days.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "chest pain");
    strcpy(symptoms[*count].condition, "Heart Attack");
    strcpy(symptoms[*count].advice, "Call emergency services immediately. Chew aspirin if not allergic.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "shortness of breath");
    strcpy(symptoms[*count].condition, "Asthma Attack");
    strcpy(symptoms[*count].advice, "Use a prescribed inhaler immediately. Seek medical help if symptoms worsen.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "headache");
    strcpy(symptoms[*count].condition, "Migraine");
    strcpy(symptoms[*count].advice, "Rest in a quiet, dark room. Take over-the-counter pain relievers if necessary.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "abdominal pain");
    strcpy(symptoms[*count].condition, "Food Poisoning");
    strcpy(symptoms[*count].advice, "Stay hydrated. Avoid solid foods until symptoms subside. Seek medical attention if severe.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "sore throat");
    strcpy(symptoms[*count].condition, "Cold/Flu");
    strcpy(symptoms[*count].advice, "Gargle with warm salt water. Stay hydrated and rest.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "dizziness");
    strcpy(symptoms[*count].condition, "Dehydration");
    strcpy(symptoms[*count].advice, "Drink plenty of fluids and rest. Seek medical attention if it persists.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "nausea");
    strcpy(symptoms[*count].condition, "Motion Sickness");
    strcpy(symptoms[*count].advice, "Take anti-nausea medication. Avoid heavy meals before travel.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "back pain");
    strcpy(symptoms[*count].condition, "Muscle Strain");
    strcpy(symptoms[*count].advice, "Apply ice or heat. Rest and avoid heavy lifting.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "joint pain");
    strcpy(symptoms[*count].condition, "Arthritis");
    strcpy(symptoms[*count].advice, "Use over-the-counter pain relief. Exercise gently and stay active.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "rash");
    strcpy(symptoms[*count].condition, "Allergic Reaction");
    strcpy(symptoms[*count].advice, "Apply a cold compress. Use antihistamine cream or medication.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "swelling");
    strcpy(symptoms[*count].condition, "Injury");
    strcpy(symptoms[*count].advice, "Elevate the affected area. Apply ice to reduce swelling.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "blurred vision");
    strcpy(symptoms[*count].condition, "Eye Strain");
    strcpy(symptoms[*count].advice, "Rest your eyes. Use artificial tears if dry eye symptoms persist.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "cough");
    strcpy(symptoms[*count].condition, "Bronchitis");
    strcpy(symptoms[*count].advice, "Stay hydrated. Use a humidifier to soothe airways.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "constipation");
    strcpy(symptoms[*count].condition, "Digestive Issue");
    strcpy(symptoms[*count].advice, "Increase fiber intake. Stay hydrated and exercise regularly.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "diarrhea");
    strcpy(symptoms[*count].condition, "Gastroenteritis");
    strcpy(symptoms[*count].advice, "Stay hydrated. Avoid dairy and fatty foods until symptoms subside.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "fatigue");
    strcpy(symptoms[*count].condition, "Anemia");
    strcpy(symptoms[*count].advice, "Eat iron-rich foods and rest. Consult a doctor for supplements.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "loss of appetite");
    strcpy(symptoms[*count].condition, "Stomach Virus");
    strcpy(symptoms[*count].advice, "Stay hydrated. Eat small, bland meals.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "sneezing");
    strcpy(symptoms[*count].condition, "Allergy");
    strcpy(symptoms[*count].advice, "Use antihistamines and avoid allergens.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "itchy eyes");
    strcpy(symptoms[*count].condition, "Conjunctivitis");
    strcpy(symptoms[*count].advice, "Avoid touching your eyes. Use artificial tears for relief.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "vomiting");
    strcpy(symptoms[*count].condition, "Food Poisoning");
    strcpy(symptoms[*count].advice, "Rehydrate with electrolyte solutions. Seek medical attention if severe.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "leg cramps");
    strcpy(symptoms[*count].condition, "Muscle Fatigue");
    strcpy(symptoms[*count].advice, "Stretch and massage the muscle. Stay hydrated.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "runny nose");
    strcpy(symptoms[*count].condition, "Common Cold");
    strcpy(symptoms[*count].advice, "Use a saline nasal spray. Stay hydrated and rest.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "toothache");
    strcpy(symptoms[*count].condition, "Dental Infection");
    strcpy(symptoms[*count].advice, "Rinse with warm salt water. Consult a dentist as soon as possible.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "ear pain");
    strcpy(symptoms[*count].condition, "Ear Infection");
    strcpy(symptoms[*count].advice, "Apply a warm compress. Avoid inserting anything into the ear.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "feeling cold");
    strcpy(symptoms[*count].condition, "Hypothermia");
    strcpy(symptoms[*count].advice, "Warm up gradually. Drink warm liquids but avoid caffeine or alcohol.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "difficulty sleeping");
    strcpy(symptoms[*count].condition, "Insomnia");
    strcpy(symptoms[*count].advice, "Avoid caffeine before bedtime. Practice relaxation techniques.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "loss of balance");
    strcpy(symptoms[*count].condition, "Inner Ear Problem");
    strcpy(symptoms[*count].advice, "Sit or lie down immediately. Avoid sudden movements.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "palpitations");
    strcpy(symptoms[*count].condition, "Stress/Anxiety");
    strcpy(symptoms[*count].advice, "Practice deep breathing. Seek medical advice if frequent.");
    (*count)++;

    strcpy(symptoms[*count].symptom, "cold hands and feet");
    strcpy(symptoms[*count].condition, "Poor Circulation");
    strcpy(symptoms[*count].advice, "Wear warm clothing. Exercise to improve blood flow.");
    (*count)++;
}


// Function to handle user input of symptoms and provide advice
void handleSymptomsInput(SymptomData symptoms[], int count) {
    char input[100];
    int found = 0;

    printf("\nEnter your symptoms (e.g., fever, chest pain): ");
    getchar();  // To clear the buffer
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline

    for (int i = 0; i < count; i++) {
        if (strstr(input, symptoms[i].symptom) != NULL) {
            printf("\nSymptom: %s\nCondition: %s\nAdvice: %s\n",
                   symptoms[i].symptom, symptoms[i].condition, symptoms[i].advice);
            saveAdviceToFile(symptoms[i].advice);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching symptoms found. Please consult a healthcare provider.\n");
    }
}

// Function to provide general first aid advice
void provideFirstAidAdvice() {
    printf("\n--- First Aid Advice ---\n");
    detailedFirstAidOptions();
}

// Detailed first aid options
void detailedFirstAidOptions() {
    char issue[50];

    printf("Enter the first aid issue (e.g., Bleeding, Burns, Choking, etc.): ");
    scanf(" %[^\n]s", issue); // Read input including spaces

    // Convert input to lowercase for case-insensitive comparison
    for (int i = 0; issue[i]; i++) {
        issue[i] = tolower(issue[i]);
    }

    if (strcmp(issue, "bleeding") == 0) {
        printf("\nBleeding: Apply pressure on the wound with a clean cloth. Elevate the injured area. Seek medical help if bleeding persists.\n");
    } else if (strcmp(issue, "burns") == 0) {
        printf("\nBurns: Hold the affected area under cool running water for at least 10 minutes. Do not apply ointments or burst blisters.\n");
    } else if (strcmp(issue, "choking") == 0) {
        printf("\nChoking: Perform the Heimlich maneuver. For infants, give back blows and chest thrusts.\n");
    } else if (strcmp(issue, "cpr") == 0) {
        printf("\nCPR: Perform chest compressions at a rate of 100-120 per minute. Provide rescue breaths if trained.\n");
    } else if (strcmp(issue, "fractures") == 0) {
        printf("\nFractures: Immobilize the injured area. Use a splint or padding. Do not attempt to realign the bone.\n");
    } else if (strcmp(issue, "poisoning") == 0) {
        printf("\nPoisoning: Identify the substance if possible. Do not induce vomiting unless instructed by a medical professional.\n");
    } else if (strcmp(issue, "heat exhaustion") == 0) {
        printf("\nHeat Exhaustion: Move the person to a cool place. Provide water to drink slowly. Loosen tight clothing.\n");
    } else if (strcmp(issue, "hypothermia") == 0) {
        printf("\nHypothermia: Warm the person gradually. Use blankets and warm liquids. Avoid applying direct heat.\n");
    } else if (strcmp(issue, "nosebleed") == 0) {
        printf("\nNosebleed: Lean forward slightly and pinch the nostrils together. Apply a cold compress to the nose bridge.\n");
    } else if (strcmp(issue, "sprains") == 0) {
        printf("\nSprains: Use the RICE method (Rest, Ice, Compression, Elevation). Avoid putting weight on the injured area.\n");
    } else if (strcmp(issue, "heart attack") == 0) {
        printf("\nHeart Attack: Call emergency services. Help the person sit comfortably. Administer aspirin if not allergic.\n");
    } else if (strcmp(issue, "stroke") == 0) {
        printf("\nStroke: Call emergency services immediately. Keep the person comfortable and monitor their condition.\n");
    } else if (strcmp(issue, "allergic reaction") == 0) {
        printf("\nAllergic Reaction: Administer an epinephrine auto-injector if available. Call emergency services if symptoms worsen.\n");
    } else if (strcmp(issue, "asthma attack") == 0) {
        printf("\nAsthma Attack: Assist the person in using their inhaler. Keep them calm and seated. Seek medical help if symptoms persist.\n");
    } else if (strcmp(issue, "seizure") == 0) {
        printf("\nSeizure: Keep the area clear of dangerous objects. Do not restrain the person or put anything in their mouth.\n");
    } else if (strcmp(issue, "eye injury") == 0) {
        printf("\nEye Injury: Rinse the eye gently with clean water. Do not rub the eye or apply pressure.\n");
    } else if (strcmp(issue, "shock") == 0) {
        printf("\nShock: Lay the person down and elevate their legs. Keep them warm and calm. Seek medical help immediately.\n");
    } else if (strcmp(issue, "fainting") == 0) {
        printf("\nFainting: Lay the person down and elevate their legs. Loosen any tight clothing and ensure fresh air.\n");
    } else if (strcmp(issue, "bee sting") == 0) {
        printf("\nBee Sting: Remove the stinger with a flat object. Wash the area and apply a cold compress.\n");
    } else if (strcmp(issue, "snake bite") == 0) {
        printf("\nSnake Bite: Keep the affected limb immobilized. Avoid applying ice or attempting to suck out venom.\n");
    } else if (strcmp(issue, "drowning") == 0) {
        printf("\nDrowning: Administer rescue breaths and chest compressions if trained. Call emergency services.\n");
    } else if (strcmp(issue, "electric shock") == 0) {
        printf("\nElectric Shock: Turn off the power source before touching the person. Call emergency services.\n");
    } else if (strcmp(issue, "sunburn") == 0) {
        printf("\nSunburn: Apply cool compresses to the area. Use aloe vera gel for soothing.\n");
    } else if (strcmp(issue, "frostbite") == 0) {
        printf("\nFrostbite: Warm the affected area gradually with warm (not hot) water. Avoid rubbing the area.\n");
    } else if (strcmp(issue, "head injury") == 0) {
        printf("\nHead Injury: Keep the person still and monitor for signs of confusion or vomiting. Seek medical attention.\n");
    } else if (strcmp(issue, "diabetic emergency") == 0) {
        printf("\nDiabetic Emergency: Provide a sugary drink or snack if conscious. Call emergency services if symptoms persist.\n");
    } else if (strcmp(issue, "cuts and scrapes") == 0) {
        printf("\nCuts and Scrapes: Wash the wound with clean water and apply a bandage.\n");
    } else if (strcmp(issue, "tooth injury") == 0) {
        printf("\nTooth Injury: Rinse the mouth with warm water. Keep any knocked-out tooth in milk or saliva and visit a dentist.\n");
    } else if (strcmp(issue, "chemical exposure") == 0) {
        printf("\nChemical Exposure: Rinse the affected area with clean water for at least 15 minutes. Remove contaminated clothing.\n");
    } else if (strcmp(issue, "animal bite") == 0) {
        printf("\nAnimal Bite: Wash the area with soap and water. Apply an antiseptic and seek medical advice.\n");
    } else {
        printf("Invalid or unrecognized first aid issue.\n");
    }
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to provide general emotional support advice
void provideEmotionalSupportAdvice() {
    printf("\n--- Emotional Support Advice ---\n");
    detailedFeelingOptions();
}

// Detailed emotional support options based on the user's feeling
void detailedFeelingOptions() {
    char feeling[50];

    printf("How are you feeling today? (e.g. stressed, sad, anxious, happy, etc.): ");
    scanf(" %[^\n]s", feeling);  // Read input including spaces

    // Convert input to lowercase for case-insensitive comparison
    for (int i = 0; feeling[i]; i++) {
        feeling[i] = tolower(feeling[i]);
    }

    if (strcmp(feeling, "stressed") == 0) {
        printf("\nIt sounds like you're feeling stressed. Here are some tips to help:\n");
        printf("1. Take regular breaks and practice mindfulness.\n");
        printf("2. Try relaxation exercises or deep breathing.\n");
        printf("3. Engage in light physical activity, like stretching or walking.\n");
    } else if (strcmp(feeling, "sad") == 0) {
        printf("\nIt sounds like you're feeling sad. Here are some tips to help:\n");
        printf("1. Reach out to loved ones for emotional support.\n");
        printf("2. Engage in hobbies or creative activities.\n");
        printf("3. Practice gratitude by reflecting on positive things in your life.\n");
    } else if (strcmp(feeling, "anxious") == 0) {
        printf("\nIt sounds like you're feeling anxious. Here are some tips to help:\n");
        printf("1. Practice mindfulness or meditation to calm your mind.\n");
        printf("2. Limit your exposure to negative news or social media.\n");
        printf("3. Try relaxation techniques like deep breathing or progressive muscle relaxation.\n");
    } else if (strcmp(feeling, "happy") == 0) {
        printf("\nIt's great to hear that you're feeling happy! Keep it up!\n");
        printf("1. Share your happiness with others.\n");
        printf("2. Continue engaging in activities that bring you joy.\n");
        printf("3. Use this positivity to stay motivated and productive.\n");
    } else if (strcmp(feeling, "bored") == 0) {
        printf("\nIt sounds like you're feeling bored. Here are some tips to help:\n");
        printf("1. Try something new, like learning a new skill or hobby.\n");
        printf("2. Engage in creative activities, like drawing or writing.\n");
        printf("3. Connect with friends or family to do something fun.\n");
    } else if (strcmp(feeling, "angry") == 0) {
        printf("\nIt sounds like you're feeling angry. Here are some tips to help:\n");
        printf("1. Practice deep breathing or mindfulness to calm down.\n");
        printf("2. Take a walk or do some physical activity to release tension.\n");
        printf("3. Express your feelings through creative outlets, like writing or drawing.\n");
    } else if (strcmp(feeling, "tired") == 0) {
        printf("\nIt sounds like you're feeling tired. Here are some tips to help:\n");
        printf("1. Try taking a short nap to recharge.\n");
        printf("2. Ensure you're getting enough rest and maintaining a sleep routine.\n");
        printf("3. Drink water and avoid too much caffeine to prevent feeling drained.\n");
    } else if (strcmp(feeling, "overwhelmed") == 0) {
        printf("\nIt sounds like you're feeling overwhelmed. Here are some tips to help:\n");
        printf("1. Break tasks down into smaller, manageable steps.\n");
        printf("2. Take a moment to breathe deeply and relax.\n");
        printf("3. Reach out to someone you trust for support.\n");
    } else {
        printf("\nI'm glad you're feeling okay. Remember, taking care of your mental health is important.\n");
        // You can add a function for general mental health tips here if needed.
    }
}

// Function to provide safety guidelines
void provideSafetyGuidelines() {
    printf("\n--- Safety Guidelines ---\n");
    detailedSafetyOptions();
}

// Detailed safety guideline options
void detailedSafetyOptions() {
    char disaster[50];

    printf("Enter the name of the disaster (e.g., Fire, Earthquake, Flood, etc.): ");
    scanf(" %[^\n]s", disaster); // Read input, including spaces

    // Convert the input to lowercase for case-insensitive comparison
    for (int i = 0; disaster[i]; i++) {
        disaster[i] = tolower(disaster[i]);
    }

    if (strcmp(disaster, "fire") == 0) {
        printf("\nFire: Stay low to the ground to avoid smoke. Exit the building immediately. Do not use elevators.\n");
    } else if (strcmp(disaster, "earthquake") == 0) {
        printf("\nEarthquake: Drop, cover, and hold on. Stay away from windows and heavy objects.\n");
    } else if (strcmp(disaster, "flood") == 0) {
        printf("\nFlood: Move to higher ground. Avoid walking or driving through floodwaters.\n");
    } else if (strcmp(disaster, "tornado") == 0) {
        printf("\nTornado: Move to a basement or interior room without windows. Cover yourself with a mattress or heavy blankets.\n");
    } else if (strcmp(disaster, "medical emergency") == 0) {
        printf("\nMedical Emergency: Call emergency services. Provide first aid as needed and stay calm.\n");
    } else if (strcmp(disaster, "volcanic eruption") == 0) {
        printf("\nVolcanic Eruption: Evacuate the area immediately. Avoid low-lying areas and stay indoors if ash is falling.\n");
    } else if (strcmp(disaster, "tsunami") == 0) {
        printf("\nTsunami: Move to higher ground immediately. Avoid coastal areas until authorities declare it safe.\n");
    } else if (strcmp(disaster, "drought") == 0) {
        printf("\nDrought: Conserve water. Avoid using excessive water for non-essential activities.\n");
    } else if (strcmp(disaster, "wildfire") == 0) {
        printf("\nWildfire: Evacuate if instructed. Close windows and doors to prevent smoke from entering.\n");
    } else if (strcmp(disaster, "landslide") == 0) {
        printf("\nLandslide: Move away from the path of the landslide. Seek higher ground.\n");
    } else if (strcmp(disaster, "avalanche") == 0) {
        printf("\nAvalanche: Move sideways to avoid the path of the snow. Try to stay on top of the snow if caught.\n");
    } else if (strcmp(disaster, "blizzards") == 0) {
        printf("\nBlizzards: Stay indoors. Stock up on supplies and ensure heating is functional.\n");
    } else if (strcmp(disaster, "heatwave") == 0) {
        printf("\nHeatwave: Stay hydrated and avoid outdoor activities during peak heat. Use fans or air conditioning.\n");
    } else if (strcmp(disaster, "sandstorm") == 0 || strcmp(disaster, "dust storm") == 0) {
        printf("\nSandstorm/Dust Storm: Cover your nose and mouth with a cloth. Stay indoors and close windows.\n");
    } else {
        printf("Invalid or unrecognized disaster name.\n");
    }
}

// Function to save advice to a file
void saveAdviceToFile(const char *advice) {
    FILE *file = fopen("medalert_advice.txt", "a");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char *timestamp = getCurrentTimestamp();
    fprintf(file, "%s - %s\n", timestamp, advice);
    fclose(file);
    printf("\nAdvice saved to 'medalert_advice.txt'.\n");
}

// Function to get the current timestamp
char *getCurrentTimestamp() {
    static char buffer[20];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    return buffer;
}
