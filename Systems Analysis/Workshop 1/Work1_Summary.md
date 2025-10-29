# 🌲 Forest Cover Type Prediction - Systems Analysis

## Workshop #1: Elements, Relationships, Sensitivity, and Chaos  
**Universidad Distrital Francisco José de Caldas**  
**Computer Engineering Program**  
**Systems Analysis & Design - 2025-III**

### 👥 Team Members
- Nicolás Martínez Pineda (20241020098)  
- Anderson Danilo Martínez Bonilla (20241020107)  
- Gabriel Esteban Gutiérrez Calderón (20221020003)  
- Jean Paul Contreras Talero (20242020131)

---

## 📋 Abstract
This workshop presents a systems analysis of the **Forest Cover Type Prediction** problem using the Roosevelt National Forest dataset from Kaggle.  
It applies principles of **systems engineering**, **sensitivity analysis**, and **chaos theory** to uncover the nonlinear and complex ecological relationships behind forest cover classification.  
Findings highlight **threshold behaviors**, **nonlinear dependencies**, and **chaotic transitions** that limit predictive model generalization and ecological interpretability.

---

## 🎯 Introduction

### Problem Context
The project addresses the challenge of predicting forest cover types using cartographic and topographic variables from the **Roosevelt National Forest (Colorado, USA)**.

- **Resolution:** 30m × 30m patches  
- **Observations:** 15,120 samples  
- **Features:** 56 cartographic variables  
- **Target Classes:** 7 distinct forest cover types  

### Key Systemic Challenges
1. **High Dimensionality** – risk of overfitting due to mixed feature types  
2. **Nonlinear Ecological Dynamics** – sensitive feedback and chaotic transitions  
3. **Computational Constraints** – need for efficiency and interpretability  

---

## 🔬 Systemic Analysis

### Core Objective
Develop a supervised ML model for multi-class forest cover prediction, mapping ecological patterns across terrain using 56 mixed-type features.

### Dataset Overview
**Features:**
- 10 Numerical topographic variables (e.g., elevation, aspect, slope, distances, hillshade)
- 4 Binary wilderness indicators  
- 40 Binary soil type variables (73% sparsity)

**Target Variable:** 7 forest cover types — each representing a unique ecological zone.

---

## 🌲 Element Relationships

### Hierarchical Variable Influence
- **Elevation** → master ecological driver (feature importance ≈ 0.42)  
- **Aspect** → regulates solar exposure, microclimate, and vegetation  
- **Slope** → affects drainage and stability  
- **Distance Metrics** → link to hydrology, roads, and fire history  

### Ecological Zonation
| Elevation Zone | Dominant Types | Characteristics |
|----------------|----------------|-----------------|
| 1,859–2,400m | Spruce/Fir, Aspen | Moist, low-elevation forests |
| 2,400–3,000m | Lodgepole & Ponderosa Pine | Mid-mountain, fire-adapted |
| 3,000–3,858m | Douglas-fir, Krummholz | Alpine transitions |

**Critical Threshold (~2,800m):**  
Small (±50m) changes cause complete ecological turnover — a hallmark of **chaotic sensitivity**.

---

## ⚠️ Complexity & Sensitivity

### Key Vulnerabilities
- **Static Dataset:** Single time snapshot, ignoring seasonal dynamics.  
- **Geographic Overfitting:** Model may not generalize beyond Colorado.  
- **Soil Type Sparsity:** 73% zeros → noise and dimensionality inflation.  
- **Hyperparameter Sensitivity:** Small tuning shifts drastically alter outcomes.  

### Curse of Dimensionality
Mixed continuous and sparse categorical variables create nonlinear interdependencies and high computational cost.

---

## 🌪️ Chaos and Randomness

### Nonlinear Dynamics
- **Elevation thresholds** at 2,400m & 3,000m cause phase transitions.  
- **Aspect–Elevation Coupling:** identical elevations yield divergent species depending on slope orientation.  
- **Fractal Boundaries:** complex, self-similar ecological transitions.

### Feedback Loops
- Vegetation alters soil and microclimate → recursive adaptation.  
- Historical fires and disturbances shape current distribution (path dependence).  
- Small random errors propagate nonlinearly, amplifying unpredictability.

---

## 📊 Machine Learning Pipeline

### Workflow
Data Acquisition → Preprocessing → EDA → Model Selection
→ Training & Validation → Prediction & Submission


**Key Steps:**
- Encode categorical data, normalize numeric features.  
- Use **tree-based models** (Random Forest, XGBoost, LightGBM) to handle nonlinearities.  
- Apply **spatial cross-validation** instead of random splits.  
- Evaluate with accuracy and F1-score, ensuring ecological interpretability.  

---

## 🔑 Key Conclusions

1. **Elevation = Master Driver**  
   Defines ecological architecture and species zonation.  

2. **Chaotic Aspect–Elevation Coupling**  
   Requires trigonometric encoding (sin/cos) for accurate modeling.  

3. **Soil Type Sparsity Crisis**  
   40 variables with 73% zeros → must be consolidated by ecological relevance.  

4. **Geographic Limitation**  
   Overfitting risk due to dataset’s single-region scope.  

5. **Threshold Sensitivity**  
   ±50m elevation variations can trigger full species replacement.  

---

## 📈 Recommendations for System Design (Workshop #2)

### Feature Engineering
- [ ] Apply trigonometric transformations for aspect  
- [ ] Bin elevation into ecological zones  
- [ ] Merge soil types by frequency/similarity  
- [ ] Model distance and hillshade interactions  

### Validation
- [ ] Implement **spatial cross-validation**  
- [ ] Test sensitivity at ecological thresholds  
- [ ] Report zone-based accuracy  

### Modeling
- [ ] Use ensemble methods (RF + XGB + LGBM)  
- [ ] Quantify uncertainty and proximity to thresholds  

### Monitoring
- [ ] Detect drift in future datasets  
- [ ] Add interpretability and alert mechanisms for uncertain predictions  

---

## 📚 References
1. Verma, V. *A Comprehensive Guide to Feature Selection Using Wrapper Methods in Python.* Analytics Vidhya, 2024.  
2. Kaggle. *Competitions Setup Documentation.*  
3. Golas, H. *S3 Storage: How It Works, Use Cases, and Tutorial.* Cloudian Blog, 2021.  

---

## 🧩 Workshop Context
- **Course:** Systems Analysis & Design (2025-III)  
- **Instructor:** Eng. Carlos Andrés Sierra, M.Sc.  
- **Objective:** Identify elements, relationships, sensitivities, and chaos-theory implications in forest cover prediction systems.  

---

## 🎓 Academic Integrity
This document was created for academic purposes at **Universidad Distrital Francisco José de Caldas**.  
All analysis and conclusions are original contributions by the listed team members.

---

**Last Updated:** October 2025  
**Status:** Systems Analysis Complete → Proceeding to Workshop #2 (System Design)
