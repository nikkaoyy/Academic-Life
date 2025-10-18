# 🌲 Forest Cover Type Prediction — Kaggle  

## Workshop 1 — Systems Analysis & Design  
### Group Project — Systems Thinking & Machine Learning  

---

## 📋 Introduction  
This repository contains the deliverables for **Workshop 1** of the *Systems Analysis & Design* course.  

The objective is to predict the **forest cover type** (7 categories of tree species) using **cartographic and ecological variables** such as elevation, slope, soil type, and distances to hydrology, roads, and fire points.  

This project combines **machine learning** with **systems thinking**, analyzing not just the dataset but also the **system’s complexity, constraints, and chaotic behaviors**.  

---

## 👥 Authors  
Developed by **Group X** for the *Systems Analysis & Design* course:  
- Nicolás Martínez Pineda 
- Anderson Danilo Bonilla
- Jean Contreras

---

## 🎯 Competition Summary  
- **Challenge:** Predict forest cover type (tree species) from cartographic variables  
- **Dataset:** 15,120 observations from *Roosevelt National Forest, Colorado*  
- **Features:** 56 variables (10 numerical + 46 binary)  
- **Target:** 7 forest cover types (perfectly balanced at 2,160 samples each)  
- **Resolution:** 30m × 30m forest patches  

---

## 📊 Analysis Structure  

This analysis follows a **four-section framework**, examining the competition from multiple perspectives:  

### 1. 🔍 Systemic Analysis  
- **Core Architecture:** Multi-class classification with hierarchical ecological relationships  
- **Feature Hierarchy:** Elevation as master variable driving species zonation  
- **Data Ecosystem:** Balanced artificial sampling creating controlled environment  
- **Element Relationships:** Topographic, spatial, and categorical feature interdependencies  

### 2. ⚠️ Complexity & Sensitivity  
- **Temporal Brittleness:** Single time-point dataset limits real-world generalization  
- **Geographic Constraints:** Restriction to Roosevelt National Forest → overfitting risks  
- **Feature Space Issues:** Sparse soil type matrix with power-law distribution  
- **Scale Mismatches:** 30m resolution may miss microhabitat variations  

### 3. 🌪️ Chaos & Randomness  
- **Ecological Tipping Points:** Elevation changes (±50m) trigger abrupt species shifts  
- **Feedback Loops:** Soil–vegetation coupling creating recursive habitat effects  
- **Non-linear Dynamics:** Aspect–elevation interactions form complex decision surfaces  
- **Stochastic Elements:** Artificial balancing and sampling methodology impacts  

### 4. 📈 Conclusion & Strategy  
- **System Strengths:** High-quality dataset, ecological validity, algorithm compatibility  
- **Critical Weaknesses:** Temporal constraints, geographic bias, artificial balance dependency  
- **Strategic Recommendations:** Distinguish *competition-focused models* vs. *real-world ecological applications*  

---

## 🎨 Visual Representations  

### Interactive System Structure Chart  
- **Dynamic Navigation:** Switch between systemic, complexity, and chaos sections  
- **Animated Data Flow:** Inputs → transformations → predictions  
- **Performance Dashboard:** Key competition metrics and evaluation indicators  
- **Strengths vs. Weaknesses:** Comparative view with actionable insights  

### Comprehensive Data Flow Diagram  
- **End-to-End Pipeline:** From raw data collection to deployment  
- **Complexity Layers:** Visual representation of system constraints  
- **Chaos Elements:** Non-linear dynamics and ecological feedback loops  
- **Applications:** Forest management, conservation, and land-use planning  

---

