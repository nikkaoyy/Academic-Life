# 🌲 Forest Cover Type Prediction System — Workshop 2

### Systems Analysis & Design — 2025-III  
**Universidad Distrital Francisco José de Caldas**  
**System Engineering Program**

---

## 👥 Team Members
- **Nicolás Martínez Pineda** (20241020098)  
- **Anderson Danilo Martínez Bonilla** (20241020107)  
- **Gabriel Esteban Gutiérrez Calderón** (20221020003)  
- **Jean Paul Contreras Talero** (20242020131)

---

## 📋 Project Overview

This repository presents the **system design** for a *Forest Cover Type Prediction System*, developed for **Workshop #2** in the *Systems Analysis & Design* course.  
It extends the analytical work from Workshop #1, providing a **production-ready architecture** that integrates ecological modeling, chaos theory, and uncertainty quantification for environmental ML systems.

### 🧩 Problem Statement
Predict forest cover types in the **Roosevelt National Forest** using cartographic data at a **30m × 30m** spatial resolution.

**Dataset Summary**
- **15,120** observations  
- **56** features (10 numerical, 4 wilderness areas, 40 soil types)  
- **7** forest cover classes (Spruce/Fir, Lodgepole Pine, Ponderosa Pine, Cottonwood/Willow, Aspen, Douglas-fir, Krummholz)

### 🚧 Key Challenges
1. Ecological threshold sensitivity at 2,400m / 2,800m / 3,200m  
2. Chaotic aspect–elevation interactions  
3. Soil type sparsity (73%)  
4. Uncertainty quantification (aleatoric & epistemic)  
5. Geographic overfitting in single-location data  

---

## 🏗️ System Architecture

The design follows a **seven-layer pipeline** architecture grounded in systems engineering principles:

1. **Data Ingestion & Collection** — integrates USGS, soil, hydrology, and fire datasets.  
2. **Data Validation & QA** — range checks, outlier detection, spatial autocorrelation.  
3. **Feature Engineering Pipeline** — domain-specific transformations (elevation, aspect, soil, distance).  
4. **Model Training & Ensemble** — RF, XGBoost, LightGBM with Bayesian tuning (Optuna).  
5. **Prediction & Uncertainty Quantification** — entropy and inter-model variance analysis.  
6. **Monitoring & Drift Detection** — KL-divergence, PSI, and Grafana dashboards.  
7. **Deployment & Serving** — real-time (FastAPI) or batch (Kubernetes) processing.

---

## 🔧 Technical Stack

| Domain | Tools / Frameworks |
|--------|--------------------|
| **Language** | Python 3.10+ |
| **Data Handling** | Pandas, NumPy, GeoPandas, PySpark |
| **ML & Optimization** | scikit-learn, XGBoost, LightGBM, PyTorch, Optuna |
| **MLOps & Infra** | MLflow, FastAPI, Redis, PostgreSQL, S3, Grafana, Prometheus, NGINX, Kubernetes |
| **Visualization** | Plotly, React |

---

## ⚙️ Systems Engineering Principles

- **Modularity** – independent functional layers  
- **Separation of Concerns** – clear boundaries per subsystem  
- **Loose Coupling** – JSON/Parquet interfaces for flexibility  
- **High Cohesion** – focused module responsibilities  
- **Scalability** – stateless design, GPU support, horizontal scaling  
- **Maintainability** – audit trails, logging, versioning, observability  

---

## 🌪️ Chaos Theory & Sensitivity Management

Critical elevation thresholds:
| Transition | Elevation | Dataset Share |
|-------------|------------|----------------|
| Foothill → Montane | 2,400m | 8.2% |
| Montane → Subalpine | 2,800m | 6.5% |
| Subalpine → Alpine | 3,200m | 4.9% |
| **Total Critical Patches** | — | **19.6%** |

**Chaos Control Measures**
- Range & schema validation  
- ±50m proximity detection  
- Dual uncertainty modeling  
- Drift detection (KL, PSI, KS tests)  
- Automated retraining triggers  

---

## 📊 Key Performance Targets

| Metric | Target |
|--------|--------|
| Ensemble Accuracy | 95.2% (design goal) |
| Real-time Latency (p95) | <100 ms |
| Batch Throughput | 1M predictions/hour |
| API Availability | 99.9% SLA |
| Model Stability (cross-seed) | <1.5% std dev |
| Drift Detection FPR | <5% |

---


---

## 🔍 From Analysis to Design

**Workshop #1 (Analysis)** revealed:
- Elevation as master ecological driver  
- Chaotic aspect–elevation relationships  
- Soil type sparsity (73%)  
- Overfitting risks in localized data  

**Workshop #2 (Design)** responds with:
- Threshold detection (±50m)  
- Soil consolidation (40 → 15 types)  
- Trigonometric aspect encoding  
- Dual uncertainty quantification  
- Spatial cross-validation & drift monitoring  
- Production-ready MLOps framework  

---

## 🎯 Requirements

### Functional
1. Process 56 features per record  
2. Ensure 100% data completeness  
3. Generate 35–40 engineered features  
4. Train RF, XGBoost, LightGBM models  
5. Integrate weighted ensemble  
6. Output uncertainty per prediction  
7. Support both API and batch modes  

### Non-Functional
- <100ms latency  
- 99.9% availability  
- GPU scalability  
- Complete logging & reproducibility  
- Ecological interpretability  

---

## 🚀 Implementation Roadmap

### Phase 1 — Core Pipeline
- [ ] Data validation module  
- [ ] Feature engineering modules (3A–3D)  
- [ ] Soil consolidation & elevation thresholds  

### Phase 2 — Model Training
- [ ] Train base models  
- [ ] Hyperparameter optimization (Optuna)  
- [ ] Ensemble integration  

### Phase 3 — Monitoring
- [ ] Drift metrics (KL, PSI)  
- [ ] Grafana dashboards  
- [ ] Retraining automation  

### Phase 4 — Deployment
- [ ] FastAPI containerization  
- [ ] Redis caching & MLflow registry  
- [ ] Kubernetes batch jobs  

### Phase 5 — Validation
- [ ] Empirical testing  
- [ ] Latency benchmarking  
- [ ] Chaos injection & geographic robustness tests  

---

## 📚 References

1. V. Verma, *Feature Selection using Wrapper Methods in Python*, Analytics Vidhya (2024)  
2. Kaggle, *Competitions Setup Documentation*, 2025  
3. E. N. Lorenz, *Deterministic Nonperiodic Flow*, *J. Atmospheric Sciences* (1963)  
4. A. Saltelli et al., *Global Sensitivity Analysis: The Primer*, Wiley (2008)  
5. USGS, *NHDPlus High Resolution Dataset*, 2025  
6. OpenTopography, *Topography Data & Tools Portal*, 2025  

---

## 🧾 Workshop Context

**Course**: Systems Analysis & Design (2025-III)  
**Instructor**: Eng. Carlos Andrés Sierra, M.Sc.  
**Institution**: Universidad Distrital Francisco José de Caldas  
**Submission Date**: October 18, 2025  

**Objective**: Translate analytical findings into a robust design integrating chaos theory, ecological modeling, and MLOps principles for real-world environmental ML deployment.

---

## 📄 License

This repository is developed for academic purposes as part of the **Computer Engineering** program at **Universidad Distrital Francisco José de Caldas**.

---

> **Note:** This document represents a conceptual design. All performance metrics are design targets pending empirical validation during subsequent implementation phases.
